function [centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound)
tic;
% Read the RGB image into workspace and turn it into grayscale
% x should be a filename, not a variable
y=ReadImage(x);
% Detect the edge using Sobel method
% A appropriate threshold needs to be selected, for most 150~200
z=EdgeDetection(y,thresh_noise);
% Find centers and radii of circles
% Need to decide boundary for radii
% the boundary needs to be narrow as possible to for speed
[centers,radii,~,maxima,~]=LoopHT(z,r_bound,thresh_radii);
DetectCircles(x,centers,radii);

toc;
end