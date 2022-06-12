#!/usr/bin/env python3
#Tim Rolston #V00920780
#Keyword out of context python progam (kwoc2.py)

from __future__ import print_function
import sys

def main():


#function to read files into list
    def readFiles(textFile):

            #creates 2d list with words per line
        tempLines = [line.rstrip('\n').split() for line in textFile]

	    #transforms words in list to be all lowercase for consistency
        tempLines = [[word.lower() for word in lines] for lines in tempLines]

        return tempLines



#function to compare and remove input file to acceptions
    def compareAndRemove(inputList, exception):
      
        tempWords = []

	    #uses nested list comprehension to compare the words in input to exception list
	    #and creates new list of "keywords"

        tempWords = [[word for word in lines if word not in exception] for lines in inputList]

        return tempWords



#function to obtain list of raw lines for print statement
    def getLines(inputFile):

        tempLine = []

        for line in inputFile:

            tempLine.append(line.rstrip('\n'))

        return tempLine



#function to order alphebetically remove dupes and transform words to upper for print format
    def sortAlphabetically(inputList):

        listWords = []
        flatKeywords = []

        flatKeywords = inputList

	    #sorts words alphabetically
        flatKeywords.sort()
	
            #remove dupes
        [listWords.append(x) for x in flatKeywords if x not in listWords]

            #turn word into all uppercase
        upperKeywords = [word.upper() for word in listWords]

        return upperKeywords



#function to flatten input list
    def flattenList(inputList):

        flatKeywords = [i for lines in inputList for i in lines]

        return flatKeywords



#function to print word in order with proper format and line number and appearance
    def printFormat(keyWordList, lineList, lineReference, leng):

        i = 0
        temp = 0

	    #nested loops for testing every keyword on every word in every line
        for word in keyWordList:

            temp = 1

            for line in lineReference:

                i = 0

                for keyWord in line:

                    if word.lower() == keyWord.lower():

                        i += 1

                    #test for multiple words in one line
                if i == 1:

                    print("%-*s" % (leng+1, word), lineList[temp-1], "({0})".format(temp))

                elif i > 1:

                    print("%-*s" % (leng+1, word), lineList[temp-1], "({0}*)".format(temp))

                temp += 1



#function to find longest word for print formatting
    def longestChar(inputList):

        lengthChar = 0

        longestWord = max(inputList, key = len)

        for char in longestWord:

            lengthChar += 1

        return lengthChar



    #main code

    inputWords = []
    linesList = []
    exceptionWords = []
    keyWords = []
    keyWordFlat = []
    orderedWords = []
    largestLen = 0


    if sys.argv[1] == "-e":

        inputArgv = sys.argv[3]
        exceptionArgv = sys.argv[2]

    elif sys.argv[2] == "-e":

        inputArgv = sys.argv[1]
        exceptionArgv = sys.argv[3]

    else:

        inputArgv = sys.argv[1]
        exceptionArgv = sys.argv[2]



        #open input txt file

    inputFile = open(inputArgv, "rt")

    inputWords = readFiles(inputFile)

    inputFile.close()

    with open(inputArgv) as f:

        linesList = getLines(f)
  


        #open exception txt file

    exceptionFile = open(exceptionArgv, "r")

    exceptionWords = readFiles(exceptionFile)

    exceptionFile.close()



        #flatten exception list for simple traversal
    exceptionWords = flattenList(exceptionWords)
    
        #create new 2d list of keywords
    keyWords = compareAndRemove(inputWords, exceptionWords)
   
       #flatten keywords into new list
    keyWordFlat = flattenList(keyWords)

        #create list for UPPER key words  
    orderedWords = sortAlphabetically(keyWordFlat)

    lowerWords = [w.lower() for w in orderedWords]

        #find longest word length
    largestLen = longestChar(lowerWords)

        #print with specified format
    printFormat(orderedWords, linesList, keyWords, largestLen)




if __name__== "__main__":
  main()
