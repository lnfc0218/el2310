function [centers,radii,Hough2,maxima,r_index]=MatHT(x,r_bound,thresh_radii)
% Use multi-dimensional arrays instead of for loops to speed up computation
%
% Inspired by some image processing blogs and this particular helpful Chinese essay, ZHU Gui-ying ZHANG Rui-lin, Circle Detection Using Hough Transform
% The link for download is http://www.paper.edu.cn/download/downPaper/200611-281
%
% This method is also mentioned in wikipedia,
% https://en.wikipedia.org/wiki/Hough_transform#Circle_detection_process,
% though more as for fixed-radius scenarios
%
% Due to the nature of multi-dimensional arrays,the limit of radii needs
% to be more specific so as to not cause a memory overflow

% r_min=46;
% r_max=55;
r_min=r_bound(1);
r_max=r_bound(2);
% tol=0.05;
% thresh_radii=50;
% step=1;
radii=[];
centers=[];

[row,col]=find(x);% get the coordinates of nonzero pixels
[sr,sc]=size(x); % get the size of input image
num=length(row);% get the sum number of nonzero pixels

Hough=zeros(sr*sc*(r_max-r_min+1),1);% initialize Hough array

% Decide coordinate a by traversing all possible b's
% r=r_min:r_max;
r2(1,1,:)=(r_min:r_max).^2;
r2=repmat(r2,[sr,num,1]);
row=repmat(row',[sr,1,r_max-r_min+1]);
col=repmat(col',[sr,1,r_max-r_min+1]);
b=1:sr;% Decide coordinate a by traversing all possible b
b=repmat(b',[1,num,r_max-r_min+1]);
a=zeros(sr,num,r_max-r_min+1,'uint16');

a=(round(col-sqrt(r2-(row-b).^2)));
% find real a's and b's
[~,y,~]=find((imag(a)==0)&(a>0));
b=b(imag(a)==0&a>0);
a=a(imag(a)==0&a>0);
% b=b(isreal(a)&&a>0);
% a=a(isreal(a)&&a>0);

ind=sub2ind([sr,sc],b,a);
ind=ind+(ceil(y/num)-1)*sc*sr;

val=ones(length(ind),1);
data=accumarray(ind,val);
Hough(1:length(data))=data;
Hough2=reshape(Hough,[sr,sc,r_max-r_min+1]);


maxima=zeros(r_max-r_min+1,1);
for i=1:r_max-r_min+1
    value=max(max(Hough2(:,:,i)));
    maxima(i)=value;    
end

r_index=find(imregionalmax(maxima));

for i=1:length(r_index)
    layer=Hough2(:,:,r_index(i));
    [row,col]=find(layer>thresh_radii);
    centers=[centers;col,row];
    radii=[radii;(r_index(i)+r_min)*ones(length(row),1)];
end
end


