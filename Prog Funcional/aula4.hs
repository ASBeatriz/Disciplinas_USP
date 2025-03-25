main = do
    putStrLn $ show $ somaNeg a
    putStrLn $ show $ somaPos a
    putStrLn $ show $ somaSe "Pos" a
    putStrLn $ show $ somaSe "Par" a
    putStrLn $ show $ somaTeste ehPar a
    putStrLn $ show $ somaTeste ehNegativo a
    putStrLn $ show $ somaTeste ehPositivo a
    putStrLn $ show $ somaTeste (\x -> x > 0) a -- lambda
    putStrLn $ show $ operaTeste ehPar multiplica 1 a -- mlutiplica os elementos pares da lista a
    putStrLn $ show $ operaTeste (\x -> mod x 2 /= 0) (\x y -> x + y) 0 a -- soma os ímpares
    putStrLn $ show $ filtra ehPositivo a -- filtra só para os positivos
    putStrLn $ show $ soma $ filtra ehPositivo a -- soma os positivos
    putStrLn $ show $ compList l1 l2
    putStrLn $ show $ compList l1 l3
    putStrLn $ show $ compList l4 l5

-- Type, Type class
-- Qual a utilidade de definir tipos?
-- Documentação, previsibilidade (ter um comportamento esperado, saber limitações, etc), prevenção de erros ocultos...

k::Integer -- sentido matematico
k = 5

m::Int -- int tipo o do C
m = 5

a :: [Integer]  
a = [3, 5, -3, 4, -8, 10, -1, 7]

-- Função Lambda
--      \ arg1 arg2 ... -> resultado
-- Função lambda são anônimas (sem nome) e são usadas quando queremos definir funções rápidas e curtas que só vão ser usadas uma vez

-- isso
i = (\x y -> x + y) 2 5
-- é o mesmo que:
somar x y = x + y
i_ = somar 2 5

--------------------------------------------------------------------------------------------------------
-- Modularização:
soma [] = 0
soma (x:xs) = x + soma xs

somaPos [] = 0  -- somar positivos
somaPos (x:xs)
   | x > 0 = x + somaPos xs
   | otherwise = somaPos xs

somaNeg [] = 0
somaNeg (x:xs)
   | x < 0 = x + somaNeg xs --- somar negativos
   | otherwise = somaNeg xs
-- ...
-- [Muita repetição, vamos modularizar!]

somaSe :: [Char] -> [Integer] -> [Integer]
somaSe cond [] = 0
somaSe cond (x:xs)
   | cond == "Pos" && x > 0 = x + somaSe cond xs
   | cond == "Neg" && x < 0 = x + somaSe cond xs
   | cond == "Par" && mod x 2 == 0 = x + somaSe cond xs
   | otherwise = somaSe cond xs
   
-- [Seria necessário mexer na função sempre que quiser adicionar outra condição...
--  Ainda dá pra melhorar:]
somaTeste teste [] = 0
somaTeste teste (x:xs)  
   | teste x = x + somaTeste teste xs
   | otherwise = somaTeste teste xs
   
prodTeste teste [] = 0  --  Definindo com produto
prodTeste teste (x:xs)  
   | teste x = x * prodTeste teste xs
   | otherwise = prodTeste teste xs
   
-- Testes
ehPositivo :: Integer -> Bool -- (definindo o tipo)
ehPositivo x = x > 0
ehPar x = mod x 2 == 0
ehNegativo x = x < 0

-- [Mas ainda tem repetição... podemos generalizar a operação!]

-- operaTeste :: (Integer -> Bool) -> (Integer -> Integer -> Integer) -> Integer -> [Integer] -> Integer
operaTeste :: (a -> Bool) -> (a -> a -> a) -> a -> [a] -> a -- genérico
operaTeste _ _ neutro [] = neutro -- (Usar underscore quando o parametro n é utilizado)
operaTeste teste op neutro (x:xs)
   | teste x = op x $ operaTeste teste op neutro xs -- = op x (operaTeste teste op neutro xs), op recebe dois argumentos
   | otherwise = operaTeste teste op neutro xs
   
-- [Versão final
--  Uma função que retorna uma lista com os elementos desejados]

-- filtra recebe uma função de tipo (a -> Bool) e retorna uma nova função que recebe uma lista do tipo a e retorna outra lista do tipo a.
filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra teste (x:xs)
    | teste x = (x:r)
    | otherwise = r
    where
        r = filtra teste xs

---------------------------------------------------------------------------------------------------------------------
-- (Haskell) Curry:
-- função sempre com um parâmetro de entrada e um parâmetro de saída;
-- uma função que parece ter múltiplos argumentos na verdade recebe um argumento e retorna outra função esperando o próximo argumento.

-- multiplica :: Integer -> (Integer -> Integer) -- recebe um inteiro que retorna uma função que recebe um inteiro e retorna um inteiro
multiplica :: Integer -> Integer -> Integer 
multiplica x y = x * y
multiplica' x = \y -> x * y
-- essas duas linhas sao exatamente a mesma coisa parano Haskell, na vdd n tem dois parâmetros em uma função

multiplica'' = \x -> (\y -> x * y)

---------------------------------------------------------------------------------------------------------------------
-- Comparação de listas
compList [] [] = True
compList [] (_:_) = False
compList (_:_) [] = False
compList (x:xs) (y:ys) 
    | x == y = compList xs ys
    | otherwise = False

-- Listas para teste
l1 = [1, 2, 3]
l2 = [1, 2, 3]
l3 = [1, 2, 2]
l4 :: [Integer]
l4 = [ ] 
l5 :: [Integer]
l5 = [ ]
