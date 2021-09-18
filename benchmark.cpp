#include <cstdint>
#include<cstdio>
#include<cstring>
class base
{
public:
    int k = 0000;
    virtual void double_the_size();
    virtual void printthis();
    void changevptr();
};
void base::printthis(){
    void**vptr=(void**)this;
    printf("obj start at %p\n",this);
    printf("vptr is %p\n",*vptr);
}
void base::changevptr(){
    printf("change vptr to:");
    scanf("%p",this);
    void **vptr = (void **)this;
    printf("vptr is %p\n", *vptr);
}
class D2 : public base
{
    unsigned long long  area;
public:
    unsigned long long  length;
    unsigned long long  width;
    virtual void double_the_size(); 
};
void base::double_the_size()
{
    ;
}
void D2::double_the_size()
{
    printf("D2-func\n");
    int nid;
    length *= 2;
    width *= 2;
}

class D3 : public D2
{
public:
    unsigned long long  volume;
    unsigned long long  height;
    virtual void double_the_size();
    virtual void count_volume()
    {
        
        volume = length * width * height;
    }
};
void D3::double_the_size()
{
    printf("D3-func\n");
    k = k + 1;
    length *= 2;
    width *= 2;
    height *= 2;
}

base *obj; //global pointer
base *obj2;
void callback(base *obj)
{
    obj->double_the_size();

    
};
void activatesth(){
    obj2=new D3;
    callback(obj2);
}
void trigger(){
    callback(obj);    
}
int main()
{
    activatesth();
    obj = new D3;
    obj->printthis();
    obj = new D2;
    obj->printthis();
    obj->changevptr();
    trigger();
}
