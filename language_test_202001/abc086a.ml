let a, b = Scanf.scanf "%d %d" (fun x y -> (x, y))
let ans = Printf.sprintf "%s" (if a * b mod 2 = 1 then "Odd" else "Even")
let () = print_endline ans
