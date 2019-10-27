#include<iostream>
using namespace std;

class Pixel {
    unsigned int iloc, jloc;
    char mark;
  public:
    Pixel()
    {
    }
    Pixel (int x,int y,char m) {
        iloc = x;
        jloc = y;
        mark=m;
    }
    Pixel (Pixel &p) {
        iloc = p.iloc;   
        jloc = p.jloc;
        mark=p.mark;
    }
    ~Pixel()
    {}
    int Get_x()
    {
        return iloc;
    }
    int Get_y()
    {
        return jloc;
    }
    char get_mark()
    {
        return mark;
    }
    void Change_mark(char m)
    {
        if(mark=='o')
            mark=m;
    }
};
class Image {
    int x_length,y_length=5;
    Pixel** p;
    public:
        Image(int x,int y)
        {
            x_length=x;
            y_length=y;
            p= new Pixel* [y_length];
            for(int i=0;i<y_length;i++)
                p[i]=new Pixel[x_length];
            for(int i=0;i<y_length;i++)
            {
                for(int j=0;j<x_length;j++)
                {
                    p[i][j]=Pixel(i,j,'o');
                }
            }
            
        }
        void Print()
        {
            for(int i=0;i<y_length;i++)
            {
                for(int j=0;j<x_length;j++)
                {
                    cout<<p[i][j].get_mark();
                    cout<<' ';
                }
                cout<<"\n";
            }
        }
        void Transform(Pixel pix,int d)
        {
            int x=pix.Get_y();
            int y=pix.Get_x();
            p[y][x].Change_mark('c');
            for(int i=0;i<=d;i++)
            {
                for(int j=0;j<d-i+1;j++)
                {
                    if(i!=0 || j!=0)
                    {
                    if(y+i<y_length && y+i>-1 && x-j>-1 && x-j<x_length)
                        p[y+i][x-j].Change_mark('x');
                    if(y+i<y_length && y+i>-1 && x+j>-1 && x+j<x_length)
                        p[y+i][x+j].Change_mark('x');
                    if(y-i<y_length && y-i>-1 && x-j>-1 && x-j<x_length)
                        p[y-i][x-j].Change_mark('x');
                    if(y-i<y_length && y-i>-1 && x+j>-1 && x+j<x_length)                                       
                        p[y-i][x+j].Change_mark('x');
                    }
                }
            }
        }
    
};

int main()
{
    int sizex,sizey;
    cin>>sizex>>sizey;
    Image img(sizex,sizey);
    int temp;
    int x,y,d;
    x=0;
    while (x!=-1)
    {
        cin>>x;
        if(x==-1)
            break;
        cin>>y;
        cin>>d;
        Pixel temp(x,y,'o');
        img.Transform(temp,d);
        
    }
   img.Print();
}

