

##################################################
class Node(object):
    def __init__(self, word, left, right):
        self.word = word
        self.left = left
        self.right = right


##################################################
def add_tree(root, word):
    assert isinstance(word, str)
    assert (isinstance(root, Node)) or (isinstance(root, type(None)))

    if root == None:
        return Node(word, None, None)
    elif word > root.word:
        print("->")
        root.right = add_tree(root.right, word)
    elif word < root.word:
        print("<-")
        root.left = add_tree(root.left, word)
    return root


##################################################
def make_tree(sentence):

    words = sentence.split(' ')
    root = None
    for word in words:
        print("adding [%s]" %word)
        root = add_tree(root, word)

    return root
        

##################################################
def print_tree(root):
    if root is not None:
        print("<-")
        print_tree(root.left)
        print("%s" %root.word)
        print("->")
        print_tree(root.right)


##################################################
if __name__ == "__main__":
    sentence = "now is the time for all good men to come to the aid of their party"    
    root = make_tree(sentence)
    print("\n end of create \n")
    print_tree(root)
    print("\nEnd\n")
