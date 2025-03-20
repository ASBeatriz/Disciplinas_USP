main = do
  putStrLn $ show $ somaTeste ehPositivo a
  --putStrLn $ show $ somaTeste ehPos a -- n sei pq n funciona
  putStrLn $ show $ somaTeste ehNegativo a
  putStrLn $ show $ somaTeste ehPar a
  putStrLn $ show $ somaTeste (\x -> x > 0) a -- lambda
  

-- type
-- type class
k::Integer -- sentido matematico
k = 5

m::Int -- int tipo o do C
m = 5

ehPositivo :: Integer -> Bool

-- qual a utilidade de definir tipos?

-- testes
ehNegativo x = x < 0
ehPositivo x = x > 0
ehPos x = \x -> x > 0 -- notação lambda
ehPar x = mod x 2 == 0
 
a :: [Integer]  
a = [3, 5, -3, 4, -8, 10, -1, 7]
soma [] = 0
soma (x:xs) = x + soma xs

somaPos [] = 0
somaPos (x:xs)
   | x > 0 = x + somaPos xs
   | otherwise = somaPos xs
   
-- Repetir o mesmo para somar negativos, pares, ímpares, etc
-- Muita repetição, vamos modularizar!

somaSe cond [] = 0
someSe cond (x:xs)
   | cond == "Pos" && x > 0 = x + somaSe cond xs
   | cond == "Neg" && x < 0 = x + somaSe cond xs
   | cond == "Par" && mod x 2 == 0 = x + somaSe cond xs
   | otherwise = somaSe xs
   
-- Ainda dá pra melhorar:
somaTeste teste [] = 0
somaTeste teste (x:xs)  
   | teste x = x + somaTeste teste xs
   | otherwise = somaTeste teste xs
   
prodTeste teste [] = 0
prodTeste teste (x:xs)  
   | teste x = x * prodTeste teste xs
   | otherwise = prodTeste teste xs
   
-- Ainda tem repetição...
operaTeste teste op neutro [] = neutro
operaTeste teste op neutro (x:xs) --n consegui ver a implementação :/ (tirei foto)
   | teste x = op x $ operaTeste teste op neutro xs -- op x (operaTeste teste op neutro) xs
   | otherwise = operaTeste teste op neutro xs
   
-- versão final 
filtra teste -- ... (foto)

-- (Haskell) Curry
-- função sempre com um parâmetro de entrada e um parâmetro de saída

-- essas duas linhas sao exatamente a mesma coisa parano Haskell, na vdd n tem dois parâmetros em uma função
-- multiplica :: Integer -> (Integer -> Integer) -- recebe um inteiro que retorna uma função que recebe um inteiro e retorna um inteiro
multiplica :: Integer -> Integer -> Integer 
multiplica x y = x * y
multiplica' x = \y -> x * y
multiplica'' = \x -> (\y -> x * y)


-- VER FOTOS PARA TERMINAR O PROGRAMA!!