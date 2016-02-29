// phongEC.frag

// These are set by the .vert code, and they're interpolated.
varying vec3 ec_vnormal, ec_vposition;

void main()
{
vec3 P, N, L, V, H;
vec4 diffuse_color = gl_FrontMaterial.diffuse; 
vec4 specular_color = gl_FrontMaterial.specular; 
float shininess = gl_FrontMaterial.shininess;

P = ec_vposition;
N = normalize(ec_vnormal);
L = normalize(gl_LightSource[0].position - P);
V = normalize(-P);				// eye position is (0,0,0)!
H = normalize(L+V);

tcolor=vec3(texture2D(mytexture,gl_TexCoord[0].st/gl_TexCoord[0].q));

diffuse_color *= max(dot(N,L),0.0);
diffuse_color *= max(dot(N,L),0.0);
specular_color *= pow(max(dot(H,N),0.0),shininess);
gl_FragColor = (diffuse_color + specular_color);
}
