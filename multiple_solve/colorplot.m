% data = textread('C:\Users\shp\Desktop\研一\算法设计\Algorithm\multiple_solve\time.txt');
% x1=[2^2,2^3,2^4,2^5,2^6,2^7,2^8,2^9,2^10,2^11,2^12];
% y1=data(:,1)';
% y2=data(:,2)';
% y3=data(:,3)';
% %y4=data(:,4)';
% time=[0,0,0,0,0,0,0,0,0,0,0];
% for(i=2:12)
%     start = clock;
%     x = rand(2^i,2^i);
%     y = rand(2^i, 2^i);
%     z=x*y;
%     finish = clock;
%     time(i-1)= etime(finish , start)*1000000;
% end;
% plot(x1,y1,x1,y2,x1,y3,x1,time);
% x=[0:1:10000];
% y=log(x);
% z=2*x;
% plot(x,y,x,z);
data = textread('/home/shp/Documents/Code/Primer/Matrix/time.txt');
% data = data(1:9,:);
x1=[2^2,2^3,2^4,2^5,2^6,2^7,2^8,2^9,2^10,2^11,2^12];
y1=data(:,1)'/1000000;
y2=data(:,2)'/1000000;
y3=data(:,3)'/1000000;
%y4=data(:,4)';
time=[0,0,0,0,0,0,0,0,0,0,0];
for(i=2:12)
    start = clock;
    x = rand(2^i,2^i);
    y = rand(2^i, 2^i);
    z=x*y;
    finish = clock;
    time(i-1)= etime(finish , start);
end;
% plot(x1,y1,x1,y2,x1,y3,x1,time);
title('Running Time Compare');
plot(x1,y1,'r--o');
xlabel('Complexity');
ylabel('Time/S');
hold on;
plot(x1,y2,'k:+');
hold on;
plot(x1,y3,'m-.*');
hold on;
plot(x1,time,'b-x');
legend('Directly','Conqur','Strassen','Matlab');



