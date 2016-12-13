clear
% Initialise matrix to storage experiment results
RadiusMax=zeros(23,1);
RadiusMin=zeros(23,1);
% All the images are renamed orderly in advance for better programming

thresh_noise=150;

for i=1:23
    Name=sprintf('test (%d).jpg',i);
    x=ReadImage(Name);
    y=EdgeDetection(x,thresh_noise);
    [~,Radius]=imfindcircles(y,[35,90]);
    % test (8).jpg cannot be identified, haven't find a reason
    if isempty(Radius)
        Radius=0;
    end
    RadiusMax(i,1)=max(Radius);
    RadiusMin(i,1)=min(Radius);
    Max=max(nonzeros(RadiusMax));
    Min=min(nonzeros(RadiusMin));
end

save results/PreExperiment RadiusMax RadiusMin Max Min


