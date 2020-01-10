%% Start

%There is no clear and clc here, the assumption is that a png image has
%been imported

%% get one of the channels only, it is enough
img = cdata(:,:,1);

%% create a string that contains everything

text = [num2str(size(img,1)) ' ' num2str(size(img,2)) newline num2str(img(1,1)) ];

for c=2:size(img,2)
    
    text = [ text ' ' num2str(img(1,c)) ];
    
end

for r=2:size(img,1)
    
    text = [text newline];
    
    for c=1:size(img,2)
        text = [ text ' ' num2str(img(r,c)) ];
    end
    
end

%% save the string to a textfile
fid = fopen('img.txt','wt');
fprintf(fid, text);
fclose(fid);