let n = Scanf.scanf " %d" (fun x -> x)
let arr = Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x))

let ans = Array.fold_left
            (fun acc x ->
              match x mod 2, x mod 3 with
              | 0, 2 -> acc + 1
              | 0, 1 -> acc + 1
              | 0, 0 -> acc + 3
              | 1, 2 -> acc + 2
              | _ -> acc
            ) 0 arr
let () = Printf.printf "%d\n" ans
