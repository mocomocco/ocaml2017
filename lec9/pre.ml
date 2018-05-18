(*目的：受け取った整数のリストを照準に並べる*)
(*quick_sort : int list ->int list*)
let rec quick_sort lst = match lst with
   []->[]
   |first :: rest ->
let take_less n lst = 
let less x =x<n 
in List. filter less lst
in let take_greater  n lst = 
let less x =x>n 
in List. filter less lst
 in    quick_sort(take_less first rest)
     @[first]
     @quick_sort(take_greater first rest)


let test1=quick_sort [5;7;3;0;9]
let test2=quick_sort [5;5;3;8;5]
