function y=ReadImage(image)
% Read image and turn it into gray  for future processing
image=['images/' image];
y=rgb2gray(imread(image));
% % y=im2double(y);
% figure()
% imshow(y)
% hold on

% % Substitute for speed
% x_1=imread(image);
% x_2=.2989*x_1(:,:,1)+.5870*x_1(:,:,2)+.1140*x_1(:,:,3);
% % y=im2double(x_2);

