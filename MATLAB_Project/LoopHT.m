function [centers,radii,A,maxima,r_index]=LoopHT(x,r_bound,thresh_radii)
r_min=r_bound(1);
r_max=r_bound(2);
tol=0.05;
% thresh_radii=9;
step=1;
radii=[];
centers=[];

[row,col]=find(x);
A=zeros(size(x,1)-2*r_min+1,size(x,2)-2*r_min+1,r_max-r_min+1,'uint16');
for r=r_min:r_max
    for a=r_min:size(x,1)-r_min
        for b=r_min:size(x,2)-r_min
            distance=(row-a).^2+(col-b).^2-r^2;
            count=length(find(distance<tol))-length(find(distance<-tol));
            if count>thresh_radii
                A(a-r_min+1,b-r_min+1,r-r_min+1)=count;
            end
%             A(a-r_min+1,b-r_min+1,r-r_min+1)=count;
        end
    end
end
maxima=zeros(r_max-r_min+1,1,'uint32');
for i=1:r_max-r_min+1
    value=max(max(A(:,:,i)));
    maxima(i)=value;    
end

r_index=find(maxima);

for i=1:length(r_index)
    layer=A(:,:,r_index(i));
    [row,col]=find(imregionalmax(layer));
    row=row+r_min;
    col=col+r_min;
    centers=[centers;col,row];% Don't know why but seems to reverse rows and columns somewhere, what's happening?
    radii=[radii;(r_index(i)+r_min)*ones(length(row),1)];
end
end
