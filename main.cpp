
#include <iostream>
#include <string>
using namespace std;

class cube
{
protected:
    string colorSqnc;
    int depth, hight, width;
    
public:
    void setColorSqnc(string);
    void setDepth(int);
    void setHight(int);
    void setWidth(int);

    string getColorSqnc(void);
    int getDepth(void);
    int getHight(void);
    int getWidth(void);

};




class particle : public cube
{

private:
    bool flagInPlace;
    int x, y, z;
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



int main()
{
    cube *mainCube;
    particle *elemArry[2];
    int i, Nitems{2};
    mainCube = new cube;
    elemArry[0] = new particle;
    elemArry[1] = new particle;
    mainCube-> setColorSqnc("ROYGBV");
    elemArry[0]->setColorSqnc("R.YGBV");
    elemArry[1]->setColorSqnc("YGVBO.");

    //cout << elemArry[0]->getColorSqnc() << endl << elemArry[0]->getOrientation()[0] << ' ' << elemArry[0]->getOrientation()[1] << endl;
    
    elemArry[0]->rotateOne(); elemArry[0]->rotateTwo();
    
    string crntClrSqnc; 
    string mainCubeClrSqnc  { mainCube->getColorSqnc() };
    bool flagFrntOk, flagBtmOk, flagLftOk;
    int frntSideNum, btmSideNum, lftSideNum;
    int blankFaceQuant;


    //cout << elemArry[0]->getColorSqnc() << endl << elemArry[0]->getOrientation()[0] << ' ' << elemArry[0]->getOrientation()[1] << endl;
    elemArry[0]->rotateTwo();
    //cout << elemArry[0]->getColorSqnc() << endl << elemArry[0]->getOrientation()[0] << ' ' << elemArry[0]->getOrientation()[1] << endl;
    
    char presentColours[2], frstPrsntClr;
    int j;
    int clrPstnNumInMain;
    for (i = 0; i < Nitems; i++)
    {
        crntClrSqnc = elemArry[i]->getColorSqnc();
        if (containsThreeColouredFaces(crntClrSqnc))
        {
            for (j = 0; j < 2; j++)
                presentColours[j] = firstNonDot(crntClrSqnc.substr(2 * j + 2, 2));
            
            frstPrsntClr = firstNonDot(crntClrSqnc.substr(0, 2));

            clrPstnNumInMain = posNumInString(frstPrsntClr, mainCubeClrSqnc);
            cout << elemArry[i]->getColorSqnc() << endl << frstPrsntClr << ' ' << clrPstnNumInMain << endl;



            

            
        }
        else
            cout << crntClrSqnc << endl << "This piece is no corner" << endl;
        
    }

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

void cube::setHight(int inHight)
{
    hight = inHight;
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

int cube::getHight(void)
{
    return hight;
}

int cube::getWidth(void)
{
    return width;
}


//front, rear, left, right
void particle::rotateOne(void)
{
    char bfr1, bfr2;
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

}

//top, bottom, left, right
void particle::rotateTwo(void)
{
    char bfr1, bfr2;
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
}


//front, rear, top, bottom
void particle::rotateThree(void)
{
    char bfr1, bfr2;
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
}

void particle::setFlagInPlace(bool newFlag)
{
    flagInPlace = newFlag;
}

particle::particle(void)
{
    orientation = "FBDULR";
}

char *particle::getOrientation(void)
{
    char shOrient[3] = { orientation[0], orientation[2] };
    

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

