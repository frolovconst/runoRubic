
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
            
            



            

            
        }
        else
            cout << crntClrSqnc << endl << "This piece is no corner" << endl;
            
        cout << elemArry[i]->getColorSqnc() << endl << elemArry[i]->getDepth() << ' ' << elemArry[i]->getHeight() << ' ' << elemArry[i]->getWidth() << endl;
        
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
    elemArry[0]->setWidth(1);
    elemArry[0]->setHeight(150);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[2] = new particle;
    elemArry[2]->setColorSqnc(".OY…");
    elemArry[2]->setDepth(340);
    elemArry[2]->setWidth(1);
    elemArry[2]->setHeight(100);
    
    elemArry[3] = new particle;
    elemArry[3]->setColorSqnc(".OY…");
    elemArry[3]->setDepth(340);
    elemArry[3]->setWidth(1);
    elemArry[3]->setHeight(140);
    

    elemArry[4] = new particle;
    elemArry[4]->setColorSqnc(".OY…");
    elemArry[4]->setDepth(340);
    elemArry[4]->setWidth(1);
    elemArry[4]->setHeight(140);    
    
    elemArry[5] = new particle;
    elemArry[5]->setColorSqnc(".OY…");
    elemArry[5]->setDepth(340);
    elemArry[5]->setWidth(1);
    elemArry[5]->setHeight(140);
    
    elemArry[6] = new particle;
    elemArry[6]->setColorSqnc(".OY…");
    elemArry[6]->setDepth(340);
    elemArry[6]->setWidth(1);
    elemArry[6]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
    
    elemArry[1] = new particle;
    elemArry[1]->setColorSqnc(".OY…");
    elemArry[1]->setDepth(340);
    elemArry[1]->setWidth(1);
    elemArry[1]->setHeight(140);
}
