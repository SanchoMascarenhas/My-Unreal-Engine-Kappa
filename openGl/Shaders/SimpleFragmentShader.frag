	#version 330 core

	in vec4 ex_Color;
	out vec4 out_Color;

	void main(void)
	{
		//out_Color = vec4(, 6.0, 6.0, 1.0);
		out_Color = ex_Color;
	}