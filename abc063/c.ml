let id = fun x -> x;;
let n = read_int ();;
let arr = Array.init n (fun _ -> Scanf.scanf "%d\n" id);;
let _ = Array.fast_sort compare arr;;

let sum = Array.fold_right (fun acc x -> x + acc) arr 0;;
let rec solve i =
  if i >= n then
    0
  else
    let sum' = sum - arr.(i) in
    if sum' mod 10 = 0 then solve (succ i) else sum';;

let () =
  (if sum mod 10 = 0 then solve 0 else sum)
|> Printf.printf "%d\n";;
