type gakusei_t ={
namae : string;
tensuu: int;
seiseki :string;
}

let gakusei_list = [
{namae="asai";tensuu=70;seiseki="?"};
{namae="tanaka";tensuu=90;seiseki="?"};
{namae="yamada";tensuu=60;seiseki="?"};
]

(*各seisekiフィールドのリストに成績を入れる*)
(*全要素に同じ処理*)

let hyouka_list lst = 
let hyouka gakusei =match gakusei with

{namae=n;tensuu=t;seiseki=s}->
{namae=n;tensuu=t;seiseki=
if t>=80 then "A" else
if t>=70 then "B" else
if t>=60 then "C" else "D"}
in List.map hyouka lst 

let count_A lst =
let seiseki_A gakusei = match gakusei with
{namae=n;tensuu=t;seiseki=s}->s="A"
in List.length (List.filter seiseki_A lst)

let heikin lst =
let add gakusei goukei = match gakusei with {tensuu=t}->t+goukei
in let add_list lst=List.fold_right add lst 0
in add_list lst / List. length lst

let heikin_A lst = 
let lst_A = List.filter seiseki_A lst in
let goukei = List.fold_right add lst_A 0 in
let ninzuu = List.length lst_A in
goukei / ninzuu
