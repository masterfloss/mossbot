MOSSBot
=======

A nxt4you and MOSS project.


Hardware
-----------
2x Grayscale Sensor: Analog sensors

1x Ultrasom: HC-SR04 (range de 2cm - 400cm)

1x Arduino Romeo


Line Follower
-----------
(semi-implementado)
line_follower\line_follower.ino
falta:
 calibrar cores inicialmente
 precisamos de utilizar os 2 sensores de cor para mais precisão
 alterar o pin do sensor em falta
 perceber o que se fazer quando se perde completamente da linha preta
 definir o que é preto
 PID??

Line Avoider
-----------
(anda dentro de um círculo)

Table Top
-----------
parecido com o line avoider, mas inicialmente calibra a cor da mesa onde está e depois mantém-se em cima da mesa evitando o preto (quando o sensor não tem nada em baixo não há cor a reflectir)

Dancing Queen
-----------
(dança e desvia-se de obstáculos, se necessário)

Follow Wall
-----------
(implementado pelo Prof. Carlos)
seguir_parede\seguir_parede.ino


Hardware
==========
Ultrasom
-----------
(implementado)
ultrasom\ultrasom.ino

Motores
-----------
(implementado)
motores\motores.ino

Sensores Cor
-----------
(semi implementado)
Deveria ter um método Calibração que media a cor umas 10 vezes e baseado nessa média e num treshold, sabiamos se estávamos a ver a "mesma cor" ou não
cor\cor.ino


