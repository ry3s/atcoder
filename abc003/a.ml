let n = read_int ()
let () = Printf.printf "%f\n" @@ (10000. *. float n *. (float n +. 1.)) /. (2. *. float n)
