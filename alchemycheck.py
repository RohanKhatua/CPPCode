def calculate_molar_mass(compound):
    # Separate the compound into its elements and count of elements
    elements_info = {}
    i = 0
    while i < len(compound):
        element = ''
        count = ''
        while i < len(compound) and compound[i].isalpha():
            element += compound[i]
            i += 1
        while i < len(compound) and compound[i].isdigit():
            count += compound[i]
            i += 1
        if element not in elements:
            
            return 0

        elements_info[element] = int(count) if count else 1
    
    # Calculate the molar mass using the elements_info and elements dictionary
    molar_mass = 0
    for element, count in elements_info.items():
        molar_mass += elements[element] * count
    
    return (molar_mass)


def get_total_molar_mass(compound1, compound2):
    
    molmass1 = calculate_molar_mass(compound1)
    molmass2 = calculate_molar_mass(compound2)
        
    flag = False    
    if (molmass1==0 or molmass2==0):
        print("Does Not Exist. You must periodically check your answers.")
        flag = True
        
        
    if (flag == False):
        print(calculate_molar_mass(compound1)+ calculate_molar_mass(compound2))


t = int(input())
for i in range(t):
    compound1=input()
    compound2=input()
    elements = {'H': 1, 'B': 11, 'C': 12, 'N': 14, 'O': 16, 'F': 19, 'P':  31, 'S': 32, 'K': 39, 'I': 127, 'Y': 89, 'V': 51}
    get_total_molar_mass(compound1, compound2)
  