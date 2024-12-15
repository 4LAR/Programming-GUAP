from graphviz import Digraph

def visualize_tree(tree):
    """Визуализирует дерево с использованием graphviz."""
    dot = Digraph(format='png')
    node_id = 0

    def add_node(node, parent_id=None):
        nonlocal node_id
        if node is None:
            return

        # Присваиваем уникальный ID узлу
        current_id = str(node_id)
        node_id += 1

        # Определяем имя узла
        if callable(node.value):
            label = node.value.__name__
        else:
            label = str(node.value)

        # Добавляем узел в граф
        dot.node(current_id, label)

        # Если есть родитель, добавляем ребро
        if parent_id is not None:
            dot.edge(parent_id, current_id)

        # Рекурсивно добавляем потомков
        if node.left is not None:
            add_node(node.left, current_id)
        if node.right is not None:
            add_node(node.right, current_id)

    # Запускаем рекурсивное построение дерева
    add_node(tree.root)

    # Сохраняем граф в файл и показываем
    dot.render('tree_visualization', view=True)

# Пример использования:
# visualize_tree(best_individual.tree)
