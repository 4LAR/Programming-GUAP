varying float x, y, z;
uniform float r_mod;
float rand(float s, float r) { return mod(mod(s, r + r_mod) * 112341.0, 1.0); }

void main() {
	//vec4 v = vec4(gl_Vertex);
	//v.z = 0.0;

  gl_FragColor = vec4(180, 0, 180, 1.0);
}
