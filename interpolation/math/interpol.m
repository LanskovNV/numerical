clear;

x = -12 : 0.01 : 12;

knots = - 12 : 2 : 12; 

% knots = load('knots.txt'); 
y = func1(x);
yKnots = func1(knots);
poly = load('output.txt');

figure;
hold on;
grid on;
plot(x, y, 'k');
plot(knots, yKnots, 'r*');
plot(x, poly, 'b--');
