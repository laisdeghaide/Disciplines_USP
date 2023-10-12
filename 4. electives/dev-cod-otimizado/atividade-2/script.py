import subprocess
import os

executavel = 'programa_ordenacao'
comando = f"gcc -pg -o {executavel} trabalho2.c"
subprocess.run(comando, shell=True)

for i in range(10):
   comando_exec = f"./{executavel}"
   subprocess.run(comando_exec, shell=True)

   pasta = f"resultado-profiling-{i + 1}"
   os.makedirs(pasta, exist_ok=True)

   comando_gprof = f"gprof {executavel} gmon.out > {pasta}/resultado-profiling.txt"
   subprocess.run(comando_gprof, shell=True)

   comando_gprof2dot = f"python3 -m gprof2dot {pasta}/resultado-profiling.txt > {pasta}/output-profiling.dot"
   subprocess.run(comando_gprof2dot, shell=True)

   comando_graphviz = f"dot -Tpng -o {pasta}/resultado-grafo.png {pasta}/output-profiling.dot"
   subprocess.run(comando_graphviz, shell=True)
