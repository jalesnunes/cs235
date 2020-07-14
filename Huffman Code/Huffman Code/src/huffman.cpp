/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Kirby, CS 235
 * Author:
 *    Davi Neves, Jales Nunes
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include <vector>           // for VECTOR container
#include "bnode.h"         // for BINARY_NODE class definition
#include "pair.h"          // for PAIR container
#include "huffman.h"       // for HUFFMAN() prototype

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;

/*******************************************
 * FindLowerFreq
 * Finds the two lowest frequences and saves the
 * two lowest frequences indexes in the array LowerFreq
 *******************************************/
void findLowerFreq(vector<HuffmanTree> vTree, int numHTree, int(&LowerFreq)[2])
{
    int i = 0, j = 1, l;
    double iFreq, jFreq, lFreq;

    iFreq = vTree[i].getTree().data.getFirst();
    jFreq = vTree[j].getTree().data.getFirst();

    for (int k = 2; k < numHTree; k++)
    {
        if (iFreq > jFreq)
        {
            l = i;
            i = j;
            j = l;
            lFreq = iFreq;
            iFreq = jFreq;
            jFreq = lFreq;
        }
        if (jFreq > vTree[k].getTree().data.getFirst())
        {
            j = k;
            jFreq = vTree[k].getTree().data.getFirst();
        }
    }
    if (iFreq > jFreq)
    {
        l = i;
        i = j;
        j = l;
        lFreq = iFreq;
        iFreq = jFreq;
        jFreq = lFreq;
    }

    LowerFreq[0] = i;
    LowerFreq[1] = j;
}

/*******************************************
 * Display
 * Displays the Huffman tree
 *******************************************/
 // for testing purpose
void display(BNode <custom::pair <double, string> >* pHead)
{
    if (pHead == NULL)
        return;

    display(pHead->pLeft);
    cout << pHead->data << " " << endl;
    display(pHead->pRight);
}

/*******************************************
 * Encode
 * Traversal the Huffman Tree to write the huffman code
 *******************************************/
 // BNode <custom::pair <double, string> > * pHead: pointer to the complete Huffman Tree
 // char arr[]: temporary array to save the huffman code
 // int top: keep track how far down we are in the HUffman tree
 // vector <string> text: the text of the file
 // string codes[]: save the huffman code at the same order of the vector text
 // int sizeText: how many "words" there is in the file
void encode(BNode <custom::pair <double, string> >* pHead, char arr[], int top, vector <string> text, string codes[], int sizeText)
{
    string code;

    if (pHead->pLeft)
    {
        arr[top] = '0';
        encode(pHead->pLeft, arr, top + 1, text, codes, sizeText);
    }
    if (pHead->pRight)
    {
        arr[top] = '1';
        encode(pHead->pRight, arr, top + 1, text, codes, sizeText);
    }

    if (!(pHead->pLeft) && !(pHead->pRight))
    {
        for (int i = 0; i < top; i++)
        {
            code = code + arr[i];
        }
        for (int i = 0; i < sizeText; i++)
        {
            if (text[i] == pHead->data.getSecond())
                codes[i] = code;
        }
    }
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string& fileName)
{
    string token;
    double freq;

    HuffmanTree hTree;
    vector <HuffmanTree> vTree;
    vector <string> vText;
    int numHTree = 0;
    int totalText;

    //reading file
    ifstream fin(fileName.c_str());
    if (fin.fail())
    {
        cout << "Error reading file!" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            fin >> token;
            fin >> freq;

            if (!fin.eof())
            {
                custom::pair <double, string> p(freq, token);
                BNode <custom::pair <double, string> > tree(p);
                hTree.setTree(tree);
                // vector with a pair frequence and token
                // it will be used to construct the complete Huffman Tree
                vTree.push_back(hTree);
                // vector only with the token
                // it will be used for the huffman code
                vText.push_back(token);
                numHTree++;
            }
        }
    }
    fin.close();
    //number of "words" of the file
    totalText = numHTree;

    // while there is more than one Huffman Tree in the vector
    while (numHTree > 1)
    {
        // temporary array to keep the indexes of two lowest frequences
        int LowerFreq[2];
        // find the indexes of two lowest frequences
        findLowerFreq(vTree, numHTree, LowerFreq);

        // create a new BNode with the sum of the two frequences
        custom::pair <double, string> p(vTree[LowerFreq[0]].getTree().data.getFirst() + vTree[LowerFreq[1]].getTree().data.getFirst(), " ");
        BNode <custom::pair <double, string> > tree(p);
        // pointers to the left and right BNode
        BNode <custom::pair <double, string> >* pLeft = new BNode <custom::pair <double, string> >(vTree[LowerFreq[0]].getTree());
        BNode <custom::pair <double, string> >* pRight = new BNode <custom::pair <double, string> >(vTree[LowerFreq[1]].getTree());
        // add the left and right BNode 
        addLeft(&tree, pLeft);
        addRight(&tree, pRight);
        hTree.setTree(tree);

        //pointer to the BNode of the last Huffman Tree in the vector
        BNode <custom::pair <double, string> >* pLast = new BNode <custom::pair <double, string> >(vTree[numHTree - 1].getTree());
        HuffmanTree lastHtree;
        lastHtree.setTree(*pLast);

        // the new tree goes into the left-most of the two slots
        // the newly vacated right-most slot is the filled with the last element in the vector
        if (LowerFreq[0] < LowerFreq[1])
        {
            vTree[LowerFreq[0]] = hTree;
            if (LowerFreq[1] != numHTree - 1)
                vTree[LowerFreq[1]] = lastHtree;
        }
        else
        {
            vTree[LowerFreq[1]] = hTree;
            if (LowerFreq[0] != numHTree - 1)
                vTree[LowerFreq[0]] = lastHtree;
        }
        // one less Huffman Tree in the vector
        numHTree--;
    }

    // create the complete Huffman Tree
    // i is at the index 0 of the vector
    HuffmanTree finalHTree = vTree[0];
    // pointer to the complete Huffman Tree
    BNode <custom::pair <double, string> >* pHead = &(finalHTree.getTree());

    // temporary array to save the huffman code
    char arr[totalText];
    // it will keep track how far down we are in the HUffman tree
    int top = 0;
    // save the huffman code at the same order of the vector text
    string codes[totalText];

    // call the encode function 
    encode(pHead, arr, top, vText, codes, totalText);
    // displays the Huffman code for each "word" of the file
    for (int i = 0; i < totalText; i++)
        cout << vText[i] << " = " << codes[i] << endl;
}




   
   
   

