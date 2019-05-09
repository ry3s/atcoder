let () =
  let s, k =
    Scanf.scanf "%s %d" (fun x y -> x, y) in

  let length = String.length s in

  let rec loop str begin_ end_ result =
    if begin_ = length then
      result 
    else
      begin
        let result = (String.sub str begin_ end_) :: result in
        if begin_ + end_ = length || end_ = k then
          loop str (begin_ + 1) 1 result
        else
          loop str begin_ (end_ + 1) result
      end
  in
  let substr = loop s 0 1 [] in
  let substr' = List.sort_uniq compare substr in
  print_endline (List.nth substr' (k - 1))
      
