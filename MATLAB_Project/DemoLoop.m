clear
close all
% Provide a direct demostration for the traditional loop method
% Each image can run forhundreds or thousands of seconds, better use a
% workstation to test it

load('data/test1_LoopHT.mat')
[centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_loop_' name],'-dpng');

load('data/test2_LoopHT.mat')
[centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_loop_' name],'-dpng');

load('data/test3_LoopHT.mat')
[centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_loop_' name],'-dpng');

load('data/test4_LoopHT.mat')
[centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_loop_' name],'-dpng');

load('data/test5_LoopHT.mat')
[centers,radii,maxima]=MainLoop(x,thresh_noise,thresh_radii,r_bound);
[~,name,~]=fileparts(x);
fig=gcf;
print(fig,['results/circled_loop_' name],'-dpng');