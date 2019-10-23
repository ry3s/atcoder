zlet a = [1;3;5;7;8;10;12];;
let b = [4;6;9;11];;
let c = [2];;

let (x, y) = Scanf.scanf "%d %d" (fun x y -> (x, y));;
let ans =
  if List.mem x a && List.mem y a then
    "Yes"
  else if List.mem x b && List.mem y b then
    "Yes"
  else if List.mem x c && List.mem y c then
    "Yes"
  else
    "No";;
let () = print_endline ans;;
