********************************************************
bool is_Power_Of_Two(unsigned int x)
{
  return x && !(x & (x – 1));
}
*****************************************************

/*------------pair sort according second element---------------*/
bool sortbysec(pair<int,int> &a, 
              pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

//*---------------------structure sort-----------*/
point a[10];   //point type array
bool compair(point a, point b)   //here point is a struct type data type //
{
        return a.x>b.x;
}
//just call
sort(a,a+10,compair);

/*-------------------------------------*/

///find the centre of a circle which passthrew the corner point of a triangle///
point centre(point a,point b,point c)
{
        point ab,ac,ans;
        ab.x=(a.x+b.x)/2;   ab.y=(a.y+b.y)/2;
        ac.x=(a.x+c.x)/2;   ac.y=(a.y+c.y)/2;
        double a1=(a.x-b.x); double b1=a.y-b.y; double c1=ab.x*a1+ab.y*b1;
        double a2=a.x-c.x;   double b2=a.y-c.y; double c2=ac.x*a2+ac.y*b2;
        double det=a1*b2-a2*b1;
        double d=b2*c1-b1*c2;
        double dd=c2*a1-a2*c1;
        ans.x=d/det;
        ans.y=dd/det;
        return ans;

}

//a segment intersect another segment or not

int orintation(point p, point q, point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0)
        return 0;
    return (val>0)?1:2;
}
bool onSeg(point p, point q, point r)
{
    if (q.x <= max(p.x,r.x)&&q.x>=min(p.x,r.x)&& q.y<=max(p.y,r.y)&&q.y>=min(p.y,r.y))
        return true;
    return false;
}

bool is_intersect(point p1,point q1,point p2,point q2)
{
    // cout<<"Ok"<<endl;
    int o1=orintation(p1,q1,p2);
    int o2=orintation(p1,q1,q2);
    int o3=orintation(p2,q2,p1);
    int o4=orintation(p2,q2,q1);

    if(o1!=o2 && o3!=o4)
        return true;
    else if(o1==0 && onSeg(p1,p2,q1))
        return true ;
    else if(o2==0 && onSeg(p1,q2,q1))
        return true;
    else if(o3==0 && onSeg(p2,p1,q2))
        return true;
    else if(o4==0 && onSeg(p2,q1,q2))
        return true;
    else
        return false;

}
///a line intersect another line or not or lie on it-----------

int area(int x1,int y1,int x2,int y2,int x3,int y3){
    return x1*y2-y1*x2+x2*y3-y2*x3+x3*y1-y3*x1;
}

void line_line_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
    int a1 = y2-y1 ;
    int b1 = x1 -x2 ;
    int c1 =  y1*x2 - x1*y2 ;
    int a2 = y4 -y3 ;
    int b2 = x3 -x4 ;
    int c2 =  y3*x4 - x3*y4 ;
    int m = (a1*b2 - b1*a2) ; 
    if( area(x1,y1,x2,y2,x3,y3)==0 && area(x1,y1,x2,y2,x4,y4)==0) 
                                        ///given points are on the line 
    {
        pf("LINE\n") ;
    }

    if(m==0)  ////never intersect each other
    {
        pf("NONE\n") ;
    }

    double x = ((b1*c2 - b2*c1)*1.0) / ((a1*b2 - a2*b1)*1.0) ;
    double y = ((c1*a2 - c2*a1)*1.0) / ((a1*b2 - a2*b1)*1.0) ;
    pf("POINT %.2lf %.2lf\n",x,y) ;  ////intersect point
}
////if a point in a triangle or in a rectangle or in a circle-------

struct point{
    double x,y;
};
struct rectangle{
    point r1,r2;
};

struct circle{
    point c1;
    double radii;
};

struct triangle{
    point a,b,c;
};

bool in_rectangle(point p1,point p2,point p){
///p1=upper left point, p2=lowert right point,p=given point
    if(p.x>p1.x && p.x<p2.x && p.y<p1.y && p.y>p2.y)
        return true;
    else
        return false;
}

bool in_circle(point c1,double r,point p)
{///c1=centre of triangle,r=radious,,p=given point
        if(dist(p.x,p.y,c1.x,c1.y)<r) return true;
        return false;
}
double area(point a,point b,point c){///area of a triangle
        return abs(0.5*(a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y));
}

bool in_triangle(point a,point b,point c,point p){
       double area1=area(a,b,p);
       double area2=area(b,c,p);
       double area3=area(a,c,p);
       double main_area=area(a,b,c);
       double total_area=area1+area2+area3;
       if(area1!=0 && area2!=0 && area3!=0)
       {
               if(total_area-main_area<=1e-1) return true;///alada alda vabe area main area 
                                 //thke samanno boro hoy..
                               ///you know that baby:)'
               else return false;
       }
       return false;
}
