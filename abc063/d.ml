let (n, a, b) = Scanf.scanf "%d %d %d" (fun a b c -> (a, b, c));;
let hps = Array.init n (fun _ -> Scanf.scanf " %d" ((+) 0));;

let rec loop left right =
  if left + 1 >= right then
    right
  else
    let mid = (left + right) / 2 in
    let c = Array.fold_left (fun count e ->
                count + max 0 ((e - mid * b + a - b - 1) / (a - b))
              ) 0 hps
    in
    if c <= mid then loop left mid else loop mid right;;

let () = Printf.printf "%d\n" @@ loop 0 1010101010;;
