let n, t = Scanf.sscanf (read_line ()) "%d %d" (fun n t -> (n, t))
let ct_arr = Array.init n (fun n ->
                 Scanf.sscanf (read_line ()) "%d %d" (fun c t -> (c, t)))
let cost = Array.fold_left (fun mini (c, t_) ->
               if c < mini && t_ <= t then
                 c
               else mini
             ) 1000000000 ct_arr

let ans = if cost = 1000000000 then
            "TLE"
          else
            Printf.sprintf "%d" cost
let () = print_endline ans;;
