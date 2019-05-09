let rec range a b = if a > b then [] else a :: range (a+1) b
let rec digit_sum x = if x <= 0 then 0 else x mod 10 + digit_sum (x/10)
let () = Scanf.scanf "%d %d %d"
           (fun n a b -> range 1 n
            |> List.filter (fun x -> let y = digit_sum x in
                                if y >= a && y <= b then true else false)
            |> List.fold_left (+) 0
            |> Printf.printf "%d\n")
               
