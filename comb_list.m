m = input('M: ')
b = input('B: ')
% m = 3;
% b = 3;
bar = m - 1;
pos_h = bar;
cnt = 0;
tot_length = m + b - 1;
s = linspace(0, 0, tot_length+1);
s(1:pos_h) = 1;
local = logical(s);
flag_begin = 0;
zero = 0;

while true
    last_pos = 0;
    for j=1: tot_length
        if s(j) == 1
            fprintf('%d ', max(0, j-last_pos-1));
            last_pos = j;
        end
    end
    fprintf('%d\n', tot_length - last_pos);
    cnt = cnt + 1;
    flag_begin = 0;
    zero = 0;
    reset = 1;
    for j = 1: pos_h
        if s(j) == 1
            flag_begin = 1;
        end
        if s(j) == 0
            zero = zero + 1;
        end
        if (s(j) == 0 && flag_begin == 1)
            s(j-zero:j-1) = 0;
            s(1:j-1-zero) = 1;
            s(j) = 1;
            reset = 0;
            break
        end
    end
    if reset == 1
        s(1:tot_length+1) = 0;
        s(1:bar - 1) = 1;
        pos_h = pos_h + 1;
        s(pos_h) = 1;
    end
    if s(tot_length+1) == 1
        fprintf('comb cal is: %d\n', nchoosek(m+b-1, m-1))
        fprintf('count solution is: %d\n', cnt);
        return
    end
end
