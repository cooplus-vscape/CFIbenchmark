class other{
    public:
        virtual int double_the_size(){
            printf("test COOP attack!\n");
            return 1; }
        void printthis(){
            void**vptr=(void**)this;
            printf("obj start at %p\n",this);
            printf("vptr is %p\n",*vptr);}
};
class base{
public:
    int k = 0000;
    virtual void double_the_size(){;}
    virtual void printthis(){
        void**vptr=(void**)this;
        printf("obj start at %p\n",this);
        printf("vptr is %p\n",*vptr);
    }
    void changevptr(){
        printf("change vptr to:");
        scanf("%p",this);
        void **vptr = (void **)this;
        printf("vptr is %p\n", *vptr);
    }
};
class D2 : public base{
public:
    uint64_t length, width;
    virtual void double_the_size(){   
        printf("D2-func\n");
        length *= 2;width *= 2;
    }
};
class D3 : public D2{
public:
    uint64_t volume, height;
    virtual void double_the_size(){   
        printf("D3-func: COOPlus attack\n");
        k = k + 1;
        length *= 2; width *= 2; height *= 2;
    }
    virtual void count_volume(){
        volume = length * width * height;
    }
};
base *obj; //global pointer
base *obj2;
void callback(base *obj){
    obj->double_the_size();};
void print_other_vptr(){
    other* ptr = new other;
    ptr->printthis();
};
void activatesth(){
    obj2=new D3;
    callback(obj2);}
void trigger(){
    callback(obj);}
void go(){
    activatesth();
    obj = new D3;
    obj->printthis();
    obj = new D2;
    obj->printthis();
    //input counterfeit vptr
    obj->changevptr();
    trigger();}   
int main(){
 print_other_vptr();  go();
};
