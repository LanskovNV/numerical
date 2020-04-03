% test 
n = 10; % num of nodes

step = 1.57 / n;
x = 0:step:1.57;
%y = load('/home/leins/polytask_4/numb/diff/diff_equations/diff_git/y_solution.txt');
y = load('/home/leins/polytask_4/numb/diff/diff_git/y_solution.txt');
x1 =0:0.0157:1.57;
y1 = func(x1);

figure;
hold on;
grid on;
plot(x, y, 'db');
plot(x, y, 'b');
plot(x1, y1, 'r');