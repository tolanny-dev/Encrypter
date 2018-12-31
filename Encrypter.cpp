/*******************************************************************************
  A program to encrypt contents of a file and store in a new file
  *  	by David Shittu
  *  Source File:	Encrypter.cpp
  *  Created:		10/22/2018
*******************************************************************************/
#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

void readChar(ifstream *file, char **read, int encryption);
// Pre: read is an 'encryption' by 'encryption' matrix
// Post: User has been prompted and has provided a file to read from
void transposeArray(char **read, char **write, int encryption);
// Pre: read was read in readChar function and write is an
// 'encryption' by 'encryption' matrix
// Post: The array has been transposed.
void writeChar(ofstream *of, char **write, int encryption);
// Pre: write is an 'encryption' by 'encryption' matrix
// Post: User has been prompted and has given a of to write to


// Global variables for this program
int ind;
int count=0;
int buff=0;

int main()
{

              string inFile,outFile;

               cout<<"Enter the name of your Source File --> ";

               cin>>inFile;

               ifstream fT(inFile.c_str());

               char text;

               int count=0;

               while(fT>>text)
                              // keep count of the chars in the file
                              count++;
               fT.close();

               ifstream f(inFile.c_str());

               cout<<"Enter the name of the destination File --> ";

               cin>>outFile;

               ofstream of(outFile.c_str());

               cout << "Enter the encryption key: ";

               int n;

               cin >> n;
               //Dynamically create 2D array for read and write
               char **r;
               char **w;

               r = new char*[n];

               for(int i=0;i<n;i++)

                              r[i] = new char[n];

               w = new char*[n];

               while(f.peek()!=EOF)
               {



                 for(int i=0;i<n;i++)

                                w[i]=new char[n];



                              readChar(&f, r, n);

                              transposeArray(r, w, n);

                              if(f.eof())

                                  buff = 1;

                              writeChar(&of,w,n);

                              for (int i=0; i<n; i++)
                  {
                    for(int j=0; j<n; j++)
                      {
                          r[i][j] = ' ';
                      }
                  }
                  for (int i=0; i<n; i++)
                  {
                    for(int j=0; j<n; j++)
                      {
                          w[i][j] = ' ';

                      }
                  }

               }

               f.close();

               of.close();

}

void readChar(ifstream *file,char **read,int encryption)

{

               int size = encryption * encryption;

               char in[size];

               file->read(in,sizeof(in));//reads from f, n2 characters and put them in 'in' array

               int index=0;

               for(int i=0;i<encryption;i++)

               {

                              for(int j=0;j<encryption;j++)

                              {

                                             read[i][j]=in[index++];//put the chars from 'in' to 'r'

                              }

               }

               ind=index;

               count++;

}

void writeChar(ofstream *of,char **write,int encryption)

{
               int cry = encryption*encryption;
               char array[cry];

               int index=0;

               for(int i=0;i<encryption;i++)

               {

                              for(int j=0;j<encryption;j++)

                              {

                                             array[index++]=write[i][j];

                                             if(buff==1 && index==ind)

                                             {

                                                           buff=2;

                                                            break;

                                             }

                              }

                              if(buff==2)

                                             break;

               }

               //if(buff==2)

               //{

              //                of->write(array,ind);

               //}

               //else

               of->write(array,encryption*encryption);
}

void transposeArray(char **read,char **write,int encryption)

{

               int index=0;

               for(int i=0;i<encryption;i++)

               {

                              for(int j=0;j<encryption;j++)

                              {

                                             write[i][j]=read[j][i];//transpose

                              }

               }

}
