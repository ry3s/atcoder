let x = Scanf.sscanf (read_line ()) "%c " (fun x -> x)
let diff = int_of_char x - int_of_char 'A' + 1

let ans = Printf.sprintf "%d" diff
let () = print_endline ans
