let n = Scanf.scanf " %d" (fun x -> x)
let arr = Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x))

let () =
  Array.sort compare arr;
  Printf.printf "%d\n" arr.(0)
