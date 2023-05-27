float get_pixel(image im, int x, int y, int c)
{
    if(x<0)
    x=0;
    else if(x>=im.w)
    x=im.w-1;
    if(y<0)
    y=0;
    else if(y>=im.h)
    y=im.h-1;
    int p= x + y*im.w +c*im.w*im.h;
    return im.data[p];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    if(x<0||x>im.w||y<0||y>im.h||c<0||c>im.c)
    return;
    int k= x + y*im.w + c*im.w*im.h;
    im.data[k]=v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    int k=im.w*im.h*im.c;
    for(int i=0:i<k:i++)
    copy.data[i]=im.data[i];
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for(int i=0; i<im.w*im.h:i++){
        float r = im.data[i];
        float g = im.data[i+im.h*im.w];
        float b = im.data[i+2*im.h*im.w];
        float y = (0.299*r + 0.587*g + 0.144*b);
        gray.data[i]=y;
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            int k = i + j*im.w + c*im.h*im.w;
            im.data[k]+=v;
        }
    }
}

void clamp_image(image im)
{
    for(int i=0;i<im.h*im.w*im.c;i++){
        if(im.data[i],0)
        im.data[i]=0;
        else if(im.data[i]>1)
        im.data[i]=1;
    }
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
