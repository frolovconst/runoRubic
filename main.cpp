
#include <iostream>
#include <string>
using namespace std;

class cube
{
protected:
    string colorSqnc;
    int depth, height, width;
    
public:
    void setColorSqnc(string);
    void setDepth(int);
    void setHeight(int);
    void setWidth(int);

    string getColorSqnc(void);
    int getDepth(void);
    int getHeight(void);
    int getWidth(void);

};




class particle : public cube
{

private:
    bool flagInPlace;
    int xCoord, yCoord, zCoord;
    char frntFace, btmFace;
    string orientation;

public:
    void rotateOne(void);
    void rotateTwo(void);
    void rotateThree(void);
    void setFlagInPlace(bool);
    particle(void);
    char *getOrientation(void);



    

};

bool inString(char, string);

int posNumInString(char, string);

int countSmblInString(char, string);

bool containsThreeColouredFaces(string);

char firstNonDot(string);

void fillElems(particle**, int);



int main()
{
    int Nitems{48};
    cube *mainCube;
    particle *elemArry[Nitems];
    fillElems(elemArry, Nitems);
    int i;
    int xAmnt=0, yAmnt=0, zAmnt=0, xStart ;
    mainCube = new cube;
    //elemArry[0] = new particle;
    //elemArry[1] = new particle;
    mainCube-> setColorSqnc("ROYGBV");
    //elemArry[0]->setColorSqnc("R.YGBV");
    //elemArry[1]->setColorSqnc("YGVBO.");
    

    //cout << elemArry[0]->getColorSqnc() << endl << elemArry[0]->getOrientation()[0] << ' ' << elemArry[0]->getOrientation()[1] << endl;
    
    elemArry[0]->rotateOne(); elemArry[0]->rotateTwo();
    elemArry[1]->rotateTwo(); elemArry[1]->rotateThree(); elemArry[1]->rotateOne(); elemArry[1]->rotateOne();
    
    string crntClrSqnc; 
    string mainCubeClrSqnc  { mainCube->getColorSqnc() };
    bool flagFrntOk, flagBtmOk, flagLftOk;
    int frntSideNum, btmSideNum, lftSideNum;
    int blankFaceQuant;




    char presentColour, frstPrsntClr;
    int j;
    int clrPstnNumInMain, clrNumInItem;
    for (i = 0; i < Nitems; i++)
    {
        crntClrSqnc = elemArry[i]->getColorSqnc();
        if (containsThreeColouredFaces(crntClrSqnc))
        {
            presentColour = firstNonDot(crntClrSqnc.substr(2, 2));
            
            frstPrsntClr        = firstNonDot(crntClrSqnc.substr(0, 2));
            clrPstnNumInMain    = posNumInString(frstPrsntClr, mainCubeClrSqnc);
            clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
            
            
            if(clrPstnNumInMain < 4)
            {
                while (clrPstnNumInMain != clrNumInItem) 
                {
                    elemArry[i]->rotateThree();
                    crntClrSqnc         = elemArry[i]->getColorSqnc();
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                }
                
                frstPrsntClr        = presentColour;
                clrPstnNumInMain    = posNumInString(frstPrsntClr, mainCubeClrSqnc);
                
                if(clrNumInItem < 2)
                {
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    while (clrPstnNumInMain != clrNumInItem) 
                    {
                        elemArry[i]->rotateTwo();
                        crntClrSqnc         = elemArry[i]->getColorSqnc();
                        clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    } 
                }
                else
                {
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    while (clrPstnNumInMain != clrNumInItem) 
                    {
                        elemArry[i]->rotateOne();
                        crntClrSqnc         = elemArry[i]->getColorSqnc();
                        clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    } 
                }
            }
            else 
            {
                while (clrPstnNumInMain != clrNumInItem) 
                {
                    elemArry[i]->rotateOne();
                    crntClrSqnc         = elemArry[i]->getColorSqnc();
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                } 
                
                frstPrsntClr        = presentColour;
                clrPstnNumInMain    = posNumInString(frstPrsntClr, mainCubeClrSqnc);
                
                if(clrNumInItem < 2)
                {
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    while (clrPstnNumInMain != clrNumInItem) 
                    {
                        elemArry[i]->rotateTwo();
                        crntClrSqnc         = elemArry[i]->getColorSqnc();
                        clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    } 
                }
                else
                {
                    clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    while (clrPstnNumInMain != clrNumInItem) 
                    {
                        elemArry[i]->rotateThree();
                        crntClrSqnc         = elemArry[i]->getColorSqnc();
                        clrNumInItem        = posNumInString(frstPrsntClr, crntClrSqnc);
                    } 
                }
            }
            
            
           
            
            
            /*if (frntSideNum == 1)
            {
                elemArry[i]->rotateOne(); elemArry[i]->rotateOne();
            }
            else if(frntSideNum < 4)    
                while (frntSideNum)
                {
                    elemArry[i]->rotateThree();
                    crntClrSqnc = elemArry[i]->getColorSqnc();
                    frntSideNum = posNumInString(mainCubeClrSqnc[0], crntClrSqnc);
                }
            else
            {
                while (frntSideNum)
                {
                    elemArry[i]->rotateOne();
                    crntClrSqnc = elemArry[i]->getColorSqnc();
                    frntSideNum = posNumInString(mainCubeClrSqnc[0], crntClrSqnc);
                }
            }*/
            
            



            

        cout << elemArry[i]->getColorSqnc() << endl << elemArry[i]->getDepth() << ' ' << elemArry[i]->getHeight() << ' ' << elemArry[i]->getWidth() << endl;    
        }
        else
            cout << crntClrSqnc << endl << "This piece is no corner" << endl;
            
        
        
    }
    
    
    //cout << elemArry[0]->getOrientation() << endl << elemArry[1]->getOrientation()  << endl;
    
   /* for (i = 0; i < Nitems; i++)
    {
        crntClrSqnc = elemArry[i]->getColorSqnc();
        flagBtmOk   = false;
        flagFrntOk  = false;
        flagLftOk   = false;


        //if corner piece
        if (inString(mainCubeClrSqnc[0], crntClrSqnc) && inString(mainCubeClrSqnc[4], crntClrSqnc) && inString(mainCubeClrSqnc[2], crntClrSqnc))
        {
            //if front not in place
            frntSideNum = posNumInString(mainCubeClrSqnc[0], crntClrSqnc);
            if (!frntSideNum)
            {
            }
            else if (frntSideNum == 1)
            {
                elemArry[i]->rotateOne(); elemArry[i]->rotateOne();
            }
            else if(frntSideNum < 4)    
                while (frntSideNum)
                {
                    elemArry[i]->rotateThree();
                    crntClrSqnc = elemArry[i]->getColorSqnc();
                    frntSideNum = posNumInString(mainCubeClrSqnc[0], crntClrSqnc);
                }
            else
            {
                while (frntSideNum)
                {
                    elemArry[i]->rotateOne();
                    crntClrSqnc = elemArry[i]->getColorSqnc();
                    frntSideNum = posNumInString(mainCubeClrSqnc[0], crntClrSqnc);
                }
            }
              
        }// end if corner stone
            
    }// end foreach
    */

    //cout << "See result sequence" << endl << elemArry[0]->getColorSqnc() << endl << elemArry[1]->getColorSqnc() << endl;


    cin.clear();
    cin.ignore(32767, '\n');
    cin.get();
    return 0;
}


void cube::setColorSqnc(string inClrSqnc)
{
    colorSqnc = inClrSqnc;
}

void cube::setDepth(int inDepth)
{
    depth = inDepth;
}

void cube::setHeight(int inHeight)
{
    height = inHeight;
}

void cube::setWidth(int inWidth)
{
    width = inWidth;
}


string cube::getColorSqnc(void)
{
    return colorSqnc;
}

int cube::getDepth(void)
{
    return depth;
}

int cube::getHeight(void)
{
    return height;
}

int cube::getWidth(void)
{
    return width;
}


//front, rear, left, right
void particle::rotateOne(void)
{
    char bfr1, bfr2;
    int bfr;
    bfr1 = colorSqnc[0];
    bfr2 = colorSqnc[1];
    colorSqnc[0] = colorSqnc[4];
    colorSqnc[1] = colorSqnc[5];
    colorSqnc[4] = bfr2;
    colorSqnc[5] = bfr1;

    bfr1 = orientation[0];
    bfr2 = orientation[1];
    orientation[0] = orientation[4];
    orientation[1] = orientation[5];
    orientation[4] = bfr2;
    orientation[5] = bfr1;
    
    bfr     = width;
    width   = depth;
    depth   = bfr;

}

//top, bottom, left, right
void particle::rotateTwo(void)
{
    char bfr1, bfr2;
    int bfr;
    bfr1 = colorSqnc[2];
    bfr2 = colorSqnc[3];
    colorSqnc[2] = colorSqnc[4];
    colorSqnc[3] = colorSqnc[5];
    colorSqnc[4] = bfr2;
    colorSqnc[5] = bfr1;

    bfr1 = orientation[2];
    bfr2 = orientation[3];
    orientation[2] = orientation[4];
    orientation[3] = orientation[5];
    orientation[4] = bfr2;
    orientation[5] = bfr1;
    
    bfr     = width;
    width   = height;
    height  = bfr;
}


//front, rear, top, bottom
void particle::rotateThree(void)
{
    char bfr1, bfr2;
    int bfr;
    bfr1 = colorSqnc[0];
    bfr2 = colorSqnc[1];
    colorSqnc[0] = colorSqnc[2];
    colorSqnc[1] = colorSqnc[3];
    colorSqnc[2] = bfr2;
    colorSqnc[3] = bfr1;

    bfr1 = orientation[0];
    bfr2 = orientation[1];
    orientation[0] = orientation[2];
    orientation[1] = orientation[3];
    orientation[2] = bfr2;
    orientation[3] = bfr1;
    
    bfr     = height;
    height  = depth;
    depth   = bfr;
}

void particle::setFlagInPlace(bool newFlag)
{
    flagInPlace = newFlag;
}

particle::particle(void)
{
    orientation = "FBDULR";
    depth       = 1;
    height      = 2;
    width       = 3;
}

char *particle::getOrientation(void)
{
    char shOrient[3] = { orientation[0], orientation[2], '\0'};
    

    return shOrient;
}

bool inString(char item, string Source)
{
    int i;
    for (i = 0; i < Source.length(); i++)
    {
        if (Source[i] == item)
            return true;
    }
    return false;
}

int posNumInString(char item, string Source)
{
    int i;
    for (i = 0; i < Source.length(); i++)
    {
        if (Source[i] == item)
            return i;
    }
    return 7;
}

int countSmblInString(char Smbl, string Source)
{
    int i, number = 0;
    for (i = 0; i < Source.length(); i++)
    {
        if (Source[i] == Smbl)
            number++;
    }
    return number;
}

bool containsThreeColouredFaces(string clrSqnc)
{
    int blankFaceQuant;
    blankFaceQuant = countSmblInString('.', clrSqnc.substr(0, 2));
    if (blankFaceQuant < 2)
    {
        blankFaceQuant = countSmblInString('.', clrSqnc.substr(2, 2));
        if (blankFaceQuant < 2)
        {
            blankFaceQuant = countSmblInString('.', clrSqnc.substr(4, 2));
            if (blankFaceQuant < 2)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
    
}

char firstNonDot(string clrSqnc)
{
    int i;
    for (i = 0; i < clrSqnc.length(); i++)
        if (clrSqnc[i] != '.')
            return clrSqnc[i];
}



void fillElems(particle **elemArry, int Nelems)
{
    int i;
    for(i=1; i<Nelems; i++)
    {
        elemArry[i] = new particle;
        elemArry[i]->setColorSqnc("R.YGBV");
    }
    
    elemArry[0] = new particle;
    elemArry[0]->setColorSqnc(".OY.B.");
    elemArry[0]->setDepth(340);
    elemArry[0]->setHeight(1);
    elemArry[0]->setWidth(150);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY...");
    elemArry[1]->setDepth(340);
    elemArry[1]->setHeight(1);
    elemArry[1]->setWidth(140);
    
    elemArry[2] = new particle;
    elemArry[2]->setColorSqnc(".OY...");
    elemArry[2]->setDepth(340);
    elemArry[2]->setHeight(1);
    elemArry[2]->setWidth(100);
    
    elemArry[3] = new particle;
    elemArry[3]->setColorSqnc(".OY..V");
    elemArry[3]->setDepth(340);
    elemArry[3]->setHeight(1);
    elemArry[3]->setWidth(110);
    

    elemArry[4] = new particle;
    elemArry[4]->setColorSqnc(".O..B.");
    elemArry[4]->setDepth(340);
    elemArry[4]->setHeight(79);
    elemArry[4]->setWidth(150);    
    
    elemArry[5] = new particle;
    elemArry[5]->setColorSqnc(".O....");
    elemArry[5]->setDepth(340);
    elemArry[5]->setHeight(79);
    elemArry[5]->setWidth(140);
    
    elemArry[6] = new particle;
    elemArry[6]->setColorSqnc(".O....");
    elemArry[6]->setDepth(340);
    elemArry[6]->setHeight(79);
    elemArry[6]->setWidth(100);
    
    elemArry[7] = new particle;
    elemArry[7]->setColorSqnc(".O...V");
    elemArry[7]->setDepth(340);
    elemArry[7]->setHeight(79);
    elemArry[7]->setWidth(110);
    
    elemArry[8] = new particle;
    elemArry[8]->setColorSqnc(".O..B.");
    elemArry[8]->setDepth(340);
    elemArry[8]->setHeight(100);
    elemArry[8]->setWidth(150);
    
    elemArry[9] = new particle;
    elemArry[9]->setColorSqnc(".O....");
    elemArry[9]->setDepth(340);
    elemArry[9]->setHeight(100);
    elemArry[9]->setWidth(140);
    
    elemArry[10] = new particle;
    elemArry[10]->setColorSqnc(".O....");
    elemArry[10]->setDepth(340);
    elemArry[10]->setHeight(100);
    elemArry[10]->setWidth(100);
    
    elemArry[11] = new particle;
    elemArry[11]->setColorSqnc(".O...V");
    elemArry[11]->setDepth(340);
    elemArry[11]->setHeight(100);
    elemArry[11]->setWidth(110);
    
    elemArry[12] = new particle;
    elemArry[12]->setColorSqnc(".O.GB.");
    elemArry[12]->setDepth(340);
    elemArry[12]->setHeight(20);
    elemArry[12]->setWidth(150);
    
    elemArry[13] = new particle;
    elemArry[13]->setColorSqnc(".O.G..");
    elemArry[13]->setDepth(340);
    elemArry[13]->setHeight(20);
    elemArry[13]->setWidth(140);
    
    elemArry[14] = new particle;
    elemArry[14]->setColorSqnc(".O.G..");
    elemArry[14]->setDepth(340);
    elemArry[14]->setHeight(20);
    elemArry[14]->setWidth(100);
    
    elemArry[15] = new particle;
    elemArry[15]->setColorSqnc(".O.G.V");
    elemArry[15]->setDepth(340);
    elemArry[15]->setHeight(20);
    elemArry[15]->setWidth(110);
    
    elemArry[16] = new particle;
    elemArry[16]->setColorSqnc("..Y.B.");
    elemArry[16]->setDepth(330);
    elemArry[16]->setHeight(1);
    elemArry[16]->setWidth(150);
    
    elemArry[17] = new particle;
    elemArry[17]->setColorSqnc("..Y...");
    elemArry[17]->setDepth(330);
    elemArry[17]->setHeight(1);
    elemArry[17]->setWidth(140);
    
    elemArry[18] = new particle;
    elemArry[18]->setColorSqnc("..Y...");
    elemArry[18]->setDepth(330);
    elemArry[18]->setHeight(1);
    elemArry[18]->setWidth(100);
    
    elemArry[19] = new particle;
    elemArry[19]->setColorSqnc("..Y..V");
    elemArry[19]->setDepth(330);
    elemArry[19]->setHeight(1);
    elemArry[19]->setWidth(110);
    
    elemArry[20] = new particle;
    elemArry[20]->setColorSqnc("....B.");
    elemArry[20]->setDepth(330);
    elemArry[20]->setHeight(79);
    elemArry[20]->setWidth(150);
    
    elemArry[21] = new particle;
    elemArry[21]->setColorSqnc("......");
    elemArry[21]->setDepth(330);
    elemArry[21]->setHeight(79);
    elemArry[21]->setWidth(140);
    
    elemArry[22] = new particle;
    elemArry[22]->setColorSqnc("......");
    elemArry[22]->setDepth(330);
    elemArry[22]->setHeight(79);
    elemArry[22]->setWidth(100);
    
    elemArry[23] = new particle;
    elemArry[23]->setColorSqnc(".....V");
    elemArry[23]->setDepth(330);
    elemArry[23]->setHeight(79);
    elemArry[23]->setWidth(110);
    
    elemArry[24] = new particle;
    elemArry[24]->setColorSqnc("....B.");
    elemArry[24]->setDepth(330);
    elemArry[24]->setHeight(100);
    elemArry[24]->setWidth(150);
    
    elemArry[25] = new particle;
    elemArry[25]->setColorSqnc("......");
    elemArry[25]->setDepth(330);
    elemArry[25]->setHeight(100);
    elemArry[25]->setWidth(140);
    
    elemArry[26] = new particle;
    elemArry[26]->setColorSqnc("......");
    elemArry[26]->setDepth(330);
    elemArry[26]->setHeight(100);
    elemArry[26]->setWidth(100);
    
    elemArry[27] = new particle;
    elemArry[27]->setColorSqnc(".....V");
    elemArry[27]->setDepth(330);
    elemArry[27]->setHeight(100);
    elemArry[27]->setWidth(110);
    
    elemArry[28] = new particle;
    elemArry[28]->setColorSqnc("...GB.");
    elemArry[28]->setDepth(330);
    elemArry[28]->setHeight(20);
    elemArry[28]->setWidth(150);
    
    elemArry[29] = new particle;
    elemArry[29]->setColorSqnc(...G..");
    elemArry[29]->setDepth(330);
    elemArry[29]->setHeight(20);
    elemArry[29]->setWidth(140);
    
    elemArry[30] = new particle;
    elemArry[30]->setColorSqnc("...G..");
    elemArry[30]->setDepth(330);
    elemArry[30]->setHeight(20);
    elemArry[30]->setWidth(100);
    
    elemArry[31] = new particle;
    elemArry[31]->setColorSqnc("...G.V");
    elemArry[31]->setDepth(330);
    elemArry[31]->setHeight(20);
    elemArry[31]->setWidth(110);
    
    elemArry[32] = new particle;
    elemArry[32]->setColorSqnc("R.Y.B.");
    elemArry[32]->setDepth(330);
    elemArry[32]->setHeight(1);
    elemArry[32]->setWidth(150);
    
    elemArry[33] = new particle;
    elemArry[33]->setColorSqnc("R.Y...");
    elemArry[33]->setDepth(330);
    elemArry[33]->setHeight(1);
    elemArry[33]->setWidth(140);
    
    elemArry[34] = new particle;
    elemArry[34]->setColorSqnc("R.Y...");
    elemArry[34]->setDepth(330);
    elemArry[34]->setHeight(1);
    elemArry[34]->setWidth(100);
    
    elemArry[35] = new particle;
    elemArry[35]->setColorSqnc("R.Y..V");
    elemArry[35]->setDepth(330);
    elemArry[35]->setHeight(1);
    elemArry[35]->setWidth(110);
    
    elemArry[36] = new particle;
    elemArry[36]->setColorSqnc("R...B.");
    elemArry[36]->setDepth(330);
    elemArry[36]->setHeight(79);
    elemArry[36]->setWidth(150);
    
    elemArry[37] = new particle;
    elemArry[37]->setColorSqnc("R.....");
    elemArry[37]->setDepth(330);
    elemArry[37]->setHeight(79);
    elemArry[37]->setWidth(140);
    
    elemArry[38] = new particle;
    elemArry[38]->setColorSqnc("R.....");
    elemArry[38]->setDepth(330);
    elemArry[38]->setHeight(79);
    elemArry[38]->setWidth(100);
    
    elemArry[39] = new particle;
    elemArry[39]->setColorSqnc("R....V");
    elemArry[39]->setDepth(330);
    elemArry[39]->setHeight(79);
    elemArry[39]->setWidth(110);
    
    elemArry[40] = new particle;
    elemArry[40]->setColorSqnc("R...B.");
    elemArry[40]->setDepth(330);
    elemArry[40]->setHeight(100);
    elemArry[40]->setWidth(150);
    
    elemArry[41] = new particle;
    elemArry[41]->setColorSqnc("R.....");
    elemArry[41]->setDepth(330);
    elemArry[41]->setHeight(100);
    elemArry[41]->setWidth(140);
    
    elemArry[42] = new particle;
    elemArry[42]->setColorSqnc("R.....");
    elemArry[42]->setDepth(330);
    elemArry[42]->setHeight(100);
    elemArry[42]->setWidth(100);
    
    elemArry[43] = new particle;
    elemArry[43]->setColorSqnc("R....V");
    elemArry[43]->setDepth(330);
    elemArry[43]->setHeight(100);
    elemArry[43]->setWidth(110);
    
    elemArry[44] = new particle;
    elemArry[44]->setColorSqnc("R..GB.");
    elemArry[44]->setDepth(330);
    elemArry[44]->setHeight(20);
    elemArry[44]->setWidth(150);
    
    elemArry[45] = new particle;
    elemArry[45]->setColorSqnc("R..G..");
    elemArry[45]->setDepth(330);
    elemArry[45]->setHeight(20);
    elemArry[45]->setWidth(140);
    
    elemArry[46] = new particle;
    elemArry[46]->setColorSqnc("R..G..");
    elemArry[46]->setDepth(330);
    elemArry[46]->setHeight(20);
    elemArry[46]->setWidth(100);
    
    elemArry[47] = new particle;
    elemArry[47]->setColorSqnc("R..G.V");
    elemArry[47]->setDepth(330);
    elemArry[47]->setHeight(20);
    elemArry[47]->setWidth(110);


}
