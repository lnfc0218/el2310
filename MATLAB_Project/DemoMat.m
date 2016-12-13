% Provide a direct demostration for the matrix method
% Each image will only run for seconds or tens of seconds, so no need to
% run on workstation
clear
close all

load('data/test1_MatHT.mat')% Loads everything we need to run the program
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test3_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');



load('data/test4_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test7_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test12_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test13_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test20_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test22_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');

load('data/test23_MatHT.mat')
[centers,radii,maxima]=MainMat(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_mtr_' name],'-dpng');