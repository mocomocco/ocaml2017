(*整数のリストを受け取ったらその中に０が含まれているのかを判定する関数contain＿zaroの定義*)
(*contain_zero : int list -> bool*)

let rec contain_zero list = match list with
  []->false
 | first::rest -> 
   if first=0 then true
              else contain_zero rest;;

let test1 = contain_zero [] = false;;
let test2 = contain_zero [1;3;6;1;0] = true;;
let test3 = contain_zero [1;2;8;7;9] = false;;
let test4 = contain_zero [0;1;2;8;0;9;0] = true;;

(*整数のリストを受け取ったら合計を返す*)
(*sum : int list ->int*)
let rec sum lst =match lst with
    [] -> 0
  | first::rest -> first + sum rest
(*テスト*)

let test1 = sum [] = 0
let test2 = sum [7] = 7
let test3 = sum [3;2] = 5
let test4 = sum [1;2;3;4;5;6;7;8] = 36
