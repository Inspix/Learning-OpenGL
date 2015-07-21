using System;
using OpenTK;
using OpenTK.Graphics.OpenGL;
using System.Drawing;
using OpenTK.Graphics;
namespace OpenTK
{
	class MainClass
	{
		[STAThread]
		public static void Main (string[] args)
		{
			using (var game = new GameWindow (1024,768)) 
			{
				// Load event - fired once before entering the mainLoop
				game.Load += (object sender, EventArgs e) => 
				{	
					game.Title = "OpenGL in C#"; 	// Set the window title;
					GL.Enable(EnableCap.Blend);		// Enable OpenGL alpha blending
					GL.BlendFunc(BlendingFactorSrc.SrcAlpha,BlendingFactorDest.OneMinusSrcAlpha); // Set the default blending calculation

				};

				// Resize event - fires when the window changes size
				// Using it to reset the Viewport on resize
				game.Resize += (object sender, EventArgs e) => 
				{
					GL.Viewport(0,0,game.Width,game.Height); 		// Set the OpenGL ViewPort(the area that it will draw to)
				};

				// Called once every N frames set by the Run method
				game.RenderFrame += (object sender, FrameEventArgs e) => 
				{
					GL.ClearColor(Color.CornflowerBlue); 			// Sets the default color of the color buffer
					GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit); // Clears individual buffers, fills the color buffer with the set clearColor

					GL.MatrixMode(MatrixMode.Projection);			// Tells OpenGL that we will use the Projection Matrix
					GL.LoadIdentity();								// Replaces the selected matrix with a Identity matrix
					GL.Ortho(-1.5, 1.5, -1.5, 1.5, 0.0, 4.0);		// Create an Orthographic matrix(parallel view with no depth(3rd dimension)

					GL.Begin(PrimitiveType.Polygon); 				// Tells OpenGL that we want to draw Verticies with the given mode, this case Polygon(deprecated, dont use it in real applications)
					GL.Color3(Color.Blue);							// Tells OpenGL that the Vertex Colors after this call will be Blue
					GL.Vertex2(-1,1);								// Sets a Vertex at the set position
					GL.Color3(Color.Red);
					GL.Vertex2(1,1);
					GL.Color3(Color.Yellow);
					GL.Vertex2(1,-1);
					GL.Color3(Color.White);
					GL.Vertex2(-1,-1);

					GL.End();										// Tells OpenGL that we are done passing our data.

					game.SwapBuffers();								// Swaps the back buffer with the front buffer. We draw on the back buffer while the front buffer is on the screen.
				};


				game.Run (); 										// Starts the mainLoop and fires onetime events
			}
		}
	}
}