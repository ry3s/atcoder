let n = read_int ()
let () =
  if n = 1 then
    print_endline "Hello World"
  else
    Printf.printf "%d\n" @@ read_int () + read_int ()
