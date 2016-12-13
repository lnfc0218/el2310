function y=EdgeDetection(image,thresh_noise)
% a self-written convlution function is attached, though not recommended
% for it is too slow
F1=[-1 0 1;
    -2 0 2;
    -1 0 1];
F2=rot90(F1,3);

Gx=imfilter(image,F1,'replicate','same');
Gy=imfilter(image,F2,'replicate','same');

Gx=double(Gx);
Gy=double(Gy);

Magn=sqrt(Gx.^2+Gy.^2);

y=Magn>thresh_noise;


