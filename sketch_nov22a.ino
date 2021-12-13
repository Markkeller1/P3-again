#include<math.h>
using namespace std;
float Px, Py, Pz;
float L1=0.229 ,L2=0.228 ,L3=0.274;
float refX = 0.265, refY = 0.1, refZ = 0.22;
float myoX, myoY, myoZ, x, y, z, rc, rf, Lx, phil1, phil2, th1, th2, th3;
void setup() 
  {
  // put your setup code here, to run once:
  Serial.begin(115200);
  float x=refX + myoX ;
  float y=refY + myoY ;
  float z=refZ + myoZ ;
  }
  

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    String info;
    info = Serial.readStringUntil('\n');
    
    int str_len = info.length();
    char char_array[str_len];
    info.toCharArray(char_array, str_len);

    
    //**********************************************************
    String a = String(info[0]);
    int a1 = a.toInt();
    String b = String(info[1]);
    int b1 = b.toInt();
    String c = String(info[2]);
    int c1 = c.toInt();

    String d = String(info[3]);
    int d1 = d.toInt();
    String e = String(info[4]);
    int e1 = e.toInt();
    String f = String(info[5]);
    int f1 = f.toInt();

    String g = String(info[6]);
    int g1 = g.toInt();
    String h = String(info[7]);
    int h1 = h.toInt();
    String i = String(info[8]);
    int i1 = i.toInt();

    String j = String(info[9]);
    int j1 = j.toInt();
    //**********************************************************
  

    int myox = (a1*100) + (b1*10) + c1;
    int myoy = (d1*100) + (e1*10) + f1;
    int myoz = (g1*100) + (h1*10) + i1;

    
   
    //**********************************************************

    if(j1 == 2)
    {
      if(myox > 140 && rc < 0.45 && x < 0.45)
      {
        myoX += 0.001;
      }
      if(myox < 100 && rc > 0 && x > 0)
      {
        myoX -= 0.001;
      }
      if(myoy > 200 && rc < 0.45 && y < 0.45)
      {
        myoY += 0.001;
      }
      if(myoy < 160 && rc > 0 && y > 0)
      {
        myoY -= 0.001;
      }
      if(myoz > 320 && rc < 0.45 && z < 0.45)
      {
        myoZ += 0.001;
      }
      if(myoz < 280 && rc > 0 && z > 0)
      {
        myoZ -= 0.001;
      }
    }

     x=refX + myoX ;
     y=refY + myoY ;
     z=refZ + myoZ ;

     if(x < 0)
     {
      x = 0;
     }
     if(y < 0)
     {
       y = 0;
     }
     if(z < 0 || z < -0)
     {
      z < 0;
     }
    //**********************************************************

    //X,Y,Z coordinats based on the refference and the myoband data.
    

    // Calculations needed for trigonometry.
    //float Lx=sqrt(pow((pow(x,2)+pow(y,2)+pow(z,2)),2));
    //float phil2=acos(((pow(L2,2)+pow(Lx,2)-pow(L3,2))/(2*L2*Lx)));
    //float phil1=atan2((z),(sqrt(pow(x,2)+pow(y,2))));

    // The thetas
    //float th1=-atan2(y,x);
    //float th2=-( phil2 + phil1);
    //float th3=acos(-(pow(L3,2)+pow(L2,2)-pow(Lx,2))/(2*L3*L2));

    //th1 = th1* 180/M_PI;
    
    //th3 = th3* 180/M_PI;
    
    rc = sqrt(pow(y,2)+pow(z,2));
    //rf = sqrt(pow(rc,2)+pow(z,2));
    th2 = acos(((pow(z,2)+pow(y,2))-(pow(L2,2)+pow(L3,2)))/(2*L2*L3));
    
    th1 = atan((((-y)*L3*sin(th2))+(z*(L2+L3*cos(th2))))/((z*L2*sin(th2))+(y*(L1+L2*cos(th2)))));
    
  
    double Fy = L2*cos(th1)+L3*cos(th1+th2);
    double Fz = L2*sin(th1)+L3*sin(th1+th2);
    th2 = th2* 180/M_PI;
    th1 = th1* 180/M_PI;
    Serial.print("[roll: "); Serial.print(myox); Serial.print("] [pitch: "); Serial.print(myoy); Serial.print("] [yaw:"); Serial.print(myoz); Serial.print("] [X: "); Serial.print(x); Serial.print("] [Y: ");Serial.print(y); Serial.print("] [Z: ");
    Serial.print(z); Serial.print("] [Fy: "); Serial.print(Fy); Serial.print("] [Fz: "); Serial.print(Fz); Serial.print("] [phil1: "); Serial.print(phil1); Serial.print("] [th1: "); Serial.print(th1); Serial.print("] [th2: "); Serial.print(th2); Serial.print("]");
    Serial.print("[th3: "); Serial.print(th3); Serial.print("] [rc: "); Serial.print(rc); Serial.print("] [rf: "); Serial.print(rf); Serial.print("]");
    
    
  
  }
    
  }
    
  
