uniform vec2 uSize;
uniform vec2 offset;
uniform float scale;

vec4 fractal(vec2 texCoord) {
			float x = 0.0;
			float y = 0.0;
			float v = 10000.0;
			float j = 10000.0;
			for (int iteration = 0; iteration < 100; ++iteration) {
				float temp = x*x-y*y+texCoord.x;
				y = 2.0*x*y+texCoord.y;
				x = temp;
				v = min(v, abs(x*x+y*y));
				j = min(j, abs(x*y));
				
				if (x*x+y*y >= 8.0) {
					float d = (float(iteration) - (log(log(sqrt(x*x+y*y))) / log(2.0))) / 80.0;
					v = (1.0 - v) / 2.0;
					j = (1.0 - j) / 1.5;
					return vec4(d,d+j,d+v,1);
				}
			}
			return vec4(0,0,0,1);
		}

void main (void)  
{     
	vec2 texCoord = (gl_FragCoord.xy/uSize) * 2.0 - vec2(1.0,1.0);
	texCoord = texCoord * scale + offset;
	gl_FragColor = fractal(texCoord);
}  
