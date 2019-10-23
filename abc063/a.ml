let a, b = Scanf.scanf "%d %d" (fun a b -> (a, b));;
let ans = if a + b >= 10 then "error" else string_of_int (a + b);;
let () = print_endline ans;;
