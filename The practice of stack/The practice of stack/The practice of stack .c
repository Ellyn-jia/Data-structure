

// ����ƥ��

bool isValid(char* s) {
	struct Stack st;    StackInit(&st, 10); 
	//��������  
	char symbols[][2] = {         { '(', ')' },        { '[', ']' },        { '{', '}' },    };  
	while (*s)   
	{       
		int i = 0;    
		for (; i < 3; ++i)      
		{           
			//���Ϊ�����ţ�����ջ
			if (*s == symbols[i][0]) 
			{             
				StackPush(&st, *s);    
				++s;            
				break;         
			}      
		}         
		if(i == 3)  
		{          
			// �ߵ�����˵��*s���������ţ�ȡ��ջ��Ԫ��     
			// �ж��Ƿ�͵�ǰ��������ƥ��        
			char top = StackTop(&st);          
			for (int j = 0; j < 3; ++j)        
			{               
				if (*s == symbols[j][1])        
				{               
					if (top == symbols[j][0])           
					{                       
						++s;                
						StackPop(&st);     
						break;            
					}                
					else             
					{               
						//���û��һ������ƥ�䣬˵����ƥ��          
						return false;               
					}           
				}       
			}      
		}