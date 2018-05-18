(*いろいろな再帰関数*)

(*受け取ったリストの要素それぞれの先頭にnをくっつける*)
(*add_to_each: int -> int list list -> int list list*)
let rec add_to_each n lst = match lst with
    [] -> [] 
  | first :: rest -> (n :: first):: add_to_each n rest
(*テスト*)
let test1 = add_to_each 1 []              = []
let test2 = add_to_each 1 [[2]]           = [[1; 2]]
let test3 = add_to_each 1 [[2]; [2; 3]]   = [[1; 2]; [1; 2; 3]]
let test4 = add_to_each 1 [ [2]; [2; 3]; [2; 3; 4]]
                       = [[1; 2]; [1; 2; 3]; [1; 2; 3; 4]]
(*整数のリストを受け取ったらその接頭語のリストを返す*)
(*prefix : int list -> (int list) list*)
let rec prefix lst = match lst with 
    []->[]
  | first :: rest -> [first]:: add_to_each first (prefix rest)

(*テスト*)
let test5 = prefix []           = []
let test6 = prefix [1]          = [[1]]
let test7 = prefix [1; 2]       = [[1]; [1; 2]]
let test8 = prefix [1; 2; 3; 4] = [[1]; [1; 2]; [1; 2; 3]; [1; 2; 3; 4]]


type gakusei_t = {
namae : string;  (*名前*)
tensuu : int;    (*点数*)
seiseki : string;(*成績*)
}

(*学生データの例*)
let gakusei1 = {namae="asai"; tensuu=70; seiseki="B"}
let gakusei2 = {namae="tanaka"; tensuu=90; seiseki="A"}
let gakusei3 = {namae="yamada"; tensuu=60; seiseki="C"}

(*学生データのリストを受け取ったらその中の最高点を返す*)
(*max_score gakusei_t list ->int*)
let rec max_score lst = match lst with
  [] -> -1
|  {namae = n; tensuu = t; seiseki = s} :: rest -> 
 let h= max_score rest in 
if t > h then t
         else h

(*テスト*)
let test1 = max_score [gakusei1] = 70 
let test2 = max_score [gakusei1; gakusei2] = 90
let test3 = max_score [gakusei1; gakusei2; gakusei3] = 90
